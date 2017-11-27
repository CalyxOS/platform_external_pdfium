// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_occur.h"

namespace {

const CXFA_Node::PropertyData kPropertyData[] = {{XFA_Element::Extras, 1, 0},
                                                 {XFA_Element::Unknown, 0, 0}};
const XFA_Attribute kAttributeData[] = {
    XFA_Attribute::Id,     XFA_Attribute::Max,     XFA_Attribute::Min,
    XFA_Attribute::Use,    XFA_Attribute::Initial, XFA_Attribute::Usehref,
    XFA_Attribute::Unknown};

constexpr wchar_t kName[] = L"occur";

}  // namespace

CXFA_Occur::CXFA_Occur(CXFA_Document* doc, XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_Template | XFA_XDPPACKET_Form),
                XFA_ObjectType::Node,
                XFA_Element::Occur,
                kPropertyData,
                kAttributeData,
                kName) {}

CXFA_Occur::~CXFA_Occur() {}
