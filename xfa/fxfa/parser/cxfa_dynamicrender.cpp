// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_dynamicrender.h"

namespace {

const XFA_Attribute kAttributeData[] = {
    XFA_Attribute::Desc, XFA_Attribute::Lock, XFA_Attribute::Unknown};

constexpr wchar_t kName[] = L"dynamicRender";

}  // namespace

CXFA_DynamicRender::CXFA_DynamicRender(CXFA_Document* doc, XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_Config,
                XFA_ObjectType::ContentNode,
                XFA_Element::DynamicRender,
                nullptr,
                kAttributeData,
                kName) {}

CXFA_DynamicRender::~CXFA_DynamicRender() {}
