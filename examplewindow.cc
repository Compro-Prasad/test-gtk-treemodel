/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <iostream>
#include "examplewindow.h"

ExampleWindow::ExampleWindow()
: m_VBox(Gtk::Orientation::ORIENTATION_VERTICAL),
  m_Button_Quit("Quit")
{
  set_title("Gtk::TreeView (custom TreeModel) example");
  set_default_size(400, 200);

  //m_VBox.set_margin(5);
  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::PolicyType::POLICY_AUTOMATIC, Gtk::PolicyType::POLICY_AUTOMATIC);

  m_VBox.pack_start(m_ScrolledWindow, Gtk::PackOptions::PACK_EXPAND_WIDGET);
  m_VBox.pack_start(m_ButtonBox, Gtk::PackOptions::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PackOptions::PACK_SHRINK);
  //m_ButtonBox.set_margin(5);
  m_ButtonBox.set_layout(Gtk::ButtonBoxStyle::BUTTONBOX_END);
  m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this, &ExampleWindow::on_button_quit) );

  //Create the Tree model:
  m_refTreeModel = ExampleTreeModel::create();
  m_TreeView.set_model(m_refTreeModel);

  //Add the TreeView's view columns, to render some of the model's columns:
  m_TreeView.append_column( "one", m_refTreeModel->get_model_column(0) );
  m_TreeView.append_column( "two", m_refTreeModel->get_model_column(1) );
  m_TreeView.append_column( "three", m_refTreeModel->get_model_column(2) );

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::on_button_quit()
{
  hide();
}
