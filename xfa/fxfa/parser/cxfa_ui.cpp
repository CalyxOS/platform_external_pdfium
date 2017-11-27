// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_ui.h"

namespace {

const CXFA_Node::PropertyData kPropertyData[] = {
    {XFA_Element::CheckButton, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::ChoiceList, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::DefaultUi, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::Barcode, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::Button, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::DateTimeEdit, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::Picture, 1, 0},
    {XFA_Element::ImageEdit, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::PasswordEdit, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::NumericEdit, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::Signature, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::TextEdit, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::ExObject, 1, XFA_PROPERTYFLAG_OneOf},
    {XFA_Element::Extras, 1, 0},
    {XFA_Element::Unknown, 0, 0}};
const XFA_Attribute kAttributeData[] = {XFA_Attribute::Id, XFA_Attribute::Use,
                                        XFA_Attribute::Usehref,
                                        XFA_Attribute::Unknown};

constexpr wchar_t kName[] = L"ui";

}  // namespace

CXFA_Ui::CXFA_Ui(CXFA_Document* doc, XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_Template | XFA_XDPPACKET_Form),
                XFA_ObjectType::Node,
                XFA_Element::Ui,
                kPropertyData,
                kAttributeData,
                kName) {}

CXFA_Ui::~CXFA_Ui() {}
