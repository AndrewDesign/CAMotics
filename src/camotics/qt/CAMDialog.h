/******************************************************************************\

    CAMotics is an Open-Source simulation and CAM software.
    Copyright (C) 2011-2017 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#pragma once

#include "CAMLayerDialog.h"

#include <cbang/SmartPointer.h>

#include <QDialog>


namespace Ui {class CAMDialog;}


namespace CAMotics {
  class CAMDialog : public QDialog {
    Q_OBJECT;

    cb::SmartPointer<Ui::CAMDialog> ui;

    CAMLayerDialog layerDialog;
    std::vector<CAMLayer> layers;
    int editRow;

  public:
    CAMDialog(QWidget *parent);

    void loadDXFLayers(const std::string &filename);
    void setUnits(GCode::ToolUnits units);

    int getSelectedRow() const;

  protected slots:
    void on_addLayerPushButton_clicked();
    void on_upPushButton_clicked();
    void on_downPushButton_clicked();
    void on_camTableWidget_activated(QModelIndex index);
    void layerDialogAccepted();
  };
}
