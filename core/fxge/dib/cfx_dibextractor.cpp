// Copyright 2017 The PDFium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "core/fxge/dib/cfx_dibextractor.h"

#include "core/fxge/dib/cfx_dibbase.h"
#include "core/fxge/dib/cfx_dibitmap.h"

CFX_DIBExtractor::CFX_DIBExtractor(const RetainPtr<CFX_DIBBase>& pSrc) {
  if (pSrc->GetBuffer().empty()) {
    m_pBitmap = pSrc->Realize();
    return;
  }
  m_pBitmap = pdfium::MakeRetain<CFX_DIBitmap>();
  if (!m_pBitmap->Create(pSrc->GetWidth(), pSrc->GetHeight(), pSrc->GetFormat(),
                         pSrc->GetBuffer().data(),
                         /*pitch=*/0)) {
    m_pBitmap.Reset();
    return;
  }

  m_pBitmap->SetPalette(pSrc->GetPaletteSpan());
}

CFX_DIBExtractor::~CFX_DIBExtractor() = default;
