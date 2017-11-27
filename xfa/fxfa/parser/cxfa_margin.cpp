// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_margin.h"

namespace {

const CXFA_Node::PropertyData kPropertyData[] = {{XFA_Element::Extras, 1, 0},
                                                 {XFA_Element::Unknown, 0, 0}};
const XFA_Attribute kAttributeData[] = {
    XFA_Attribute::Id,        XFA_Attribute::Use,
    XFA_Attribute::LeftInset, XFA_Attribute::BottomInset,
    XFA_Attribute::TopInset,  XFA_Attribute::RightInset,
    XFA_Attribute::Usehref,   XFA_Attribute::Unknown};

constexpr wchar_t kName[] = L"margin";

}  // namespace

CXFA_Margin::CXFA_Margin(CXFA_Document* doc, XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_Template | XFA_XDPPACKET_Form),
                XFA_ObjectType::Node,
                XFA_Element::Margin,
                kPropertyData,
                kAttributeData,
                kName) {}

CXFA_Margin::~CXFA_Margin() {}
