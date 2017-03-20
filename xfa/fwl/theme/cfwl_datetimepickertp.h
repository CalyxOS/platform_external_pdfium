// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FWL_THEME_CFWL_DATETIMEPICKERTP_H_
#define XFA_FWL_THEME_CFWL_DATETIMEPICKERTP_H_

#include "xfa/fwl/theme/cfwl_widgettp.h"

class CFWL_DateTimePickerTP : public CFWL_WidgetTP {
 public:
  CFWL_DateTimePickerTP();
  ~CFWL_DateTimePickerTP() override;

  // CFWL_WidgetTP
  void DrawBackground(CFWL_ThemeBackground* pParams) override;

 protected:
  void DrawDropDownButton(CFWL_ThemeBackground* pParams, CFX_Matrix* pMatrix);
};

#endif  // XFA_FWL_THEME_CFWL_DATETIMEPICKERTP_H_
