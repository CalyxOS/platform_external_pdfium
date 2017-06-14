// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "core/fxcodec/codec/ccodec_bmpmodule.h"

#include "core/fxcodec/codec/codec_int.h"
#include "core/fxcodec/fx_codec.h"
#include "core/fxcodec/lbmp/fx_bmp.h"
#include "core/fxcrt/cfx_unowned_ptr.h"
#include "core/fxge/fx_dib.h"
#include "third_party/base/ptr_util.h"

CBmpContext::CBmpContext(BMPDecompressor* pBmp,
                         CCodec_BmpModule* pModule,
                         CCodec_BmpModule::Delegate* pDelegate)
    : m_pBmp(pBmp), m_pModule(pModule), m_pDelegate(pDelegate) {
  memset(m_szLastError, 0, sizeof(m_szLastError));
}

CBmpContext::~CBmpContext() {
  bmp_destroy_decompress(&m_pBmp);
}

CCodec_BmpModule::CCodec_BmpModule() {}

CCodec_BmpModule::~CCodec_BmpModule() {}

std::unique_ptr<CCodec_BmpModule::Context> CCodec_BmpModule::Start(
    Delegate* pDelegate) {
  BMPDecompressor* pBmp = bmp_create_decompress();
  if (!pBmp)
    return nullptr;

  auto p = pdfium::MakeUnique<CBmpContext>(pBmp, this, pDelegate);
  p->m_pBmp->context_ptr = p.get();
  p->m_pBmp->err_ptr = p->m_szLastError;
  return p;
}

int32_t CCodec_BmpModule::ReadHeader(Context* pContext,
                                     int32_t* width,
                                     int32_t* height,
                                     bool* tb_flag,
                                     int32_t* components,
                                     int32_t* pal_num,
                                     uint32_t** pal_pp,
                                     CFX_DIBAttribute* pAttribute) {
  auto* ctx = static_cast<CBmpContext*>(pContext);
  if (setjmp(ctx->m_pBmp->jmpbuf))
    return 0;

  int32_t ret = ctx->m_pBmp->ReadHeader();
  if (ret != 1)
    return ret;

  *width = ctx->m_pBmp->width;
  *height = ctx->m_pBmp->height;
  *tb_flag = ctx->m_pBmp->imgTB_flag;
  *components = ctx->m_pBmp->components;
  *pal_num = ctx->m_pBmp->pal_num;
  *pal_pp = ctx->m_pBmp->pal_ptr;
  if (pAttribute) {
    pAttribute->m_wDPIUnit = FXCODEC_RESUNIT_METER;
    pAttribute->m_nXDPI = ctx->m_pBmp->dpi_x;
    pAttribute->m_nYDPI = ctx->m_pBmp->dpi_y;
    pAttribute->m_nBmpCompressType = ctx->m_pBmp->compress_flag;
  }
  return 1;
}

int32_t CCodec_BmpModule::LoadImage(Context* pContext) {
  auto* ctx = static_cast<CBmpContext*>(pContext);
  if (setjmp(ctx->m_pBmp->jmpbuf))
    return 0;

  return ctx->m_pBmp->DecodeImage();
}

uint32_t CCodec_BmpModule::GetAvailInput(Context* pContext,
                                         uint8_t** avail_buf_ptr) {
  auto* ctx = static_cast<CBmpContext*>(pContext);
  return ctx->m_pBmp->GetAvailInput(avail_buf_ptr);
}

void CCodec_BmpModule::Input(Context* pContext,
                             const uint8_t* src_buf,
                             uint32_t src_size) {
  auto* ctx = static_cast<CBmpContext*>(pContext);
  ctx->m_pBmp->SetInputBuffer(const_cast<uint8_t*>(src_buf), src_size);
}
