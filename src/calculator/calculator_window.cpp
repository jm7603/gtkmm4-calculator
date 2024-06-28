//
// Created by jm on 2024/6/15.
//

#include "calculator_window.hpp"
#include "../interpreter/parser.hpp"

CalculatorWindow::CalculatorWindow(Window *window,
                                   const Glib::RefPtr<Gtk::Builder> &ref_glade,
                                   const Glib::RefPtr<Gtk::CssProvider> &ref_provider)
    : Gtk::Window(std::move(*window)), m_ref_builder(ref_glade), m_ref_css_provider(ref_provider) {

  set_resizable(false);
  setupWidgets();

}

void CalculatorWindow::putCharToDisplay(const std::string &str) {
  Glib::ustring label_content = m_label_display->get_label();
  //if (label_content == "0" || label_content == "ERROR") label_content = "";
  if (label_content == "ERROR") label_content = "";
  ss_display << label_content << str;
  m_label_display->set_label(ss_display.str());
  ss_display.str("");
}

void CalculatorWindow::setupWidgets() {
  m_label_display = m_ref_builder->get_widget<Gtk::Label>("display");

  m_button_clear = m_ref_builder->get_widget<Gtk::Button>("input_clear");
  m_button_lparen = m_ref_builder->get_widget<Gtk::Button>("input_lparen");
  m_button_rparen = m_ref_builder->get_widget<Gtk::Button>("input_rparen");

  m_button_plus = m_ref_builder->get_widget<Gtk::Button>("input_plus");
  m_button_minus = m_ref_builder->get_widget<Gtk::Button>("input_minus");
  m_button_multiply = m_ref_builder->get_widget<Gtk::Button>("input_multiply");
  m_button_divide = m_ref_builder->get_widget<Gtk::Button>("input_divide");
  m_button_equal = m_ref_builder->get_widget<Gtk::Button>("input_equal");

  m_button_0 = m_ref_builder->get_widget<Gtk::Button>("input_0");
  m_button_1 = m_ref_builder->get_widget<Gtk::Button>("input_1");
  m_button_2 = m_ref_builder->get_widget<Gtk::Button>("input_2");
  m_button_3 = m_ref_builder->get_widget<Gtk::Button>("input_3");
  m_button_4 = m_ref_builder->get_widget<Gtk::Button>("input_4");
  m_button_5 = m_ref_builder->get_widget<Gtk::Button>("input_5");
  m_button_6 = m_ref_builder->get_widget<Gtk::Button>("input_6");
  m_button_7 = m_ref_builder->get_widget<Gtk::Button>("input_7");
  m_button_8 = m_ref_builder->get_widget<Gtk::Button>("input_8");
  m_button_9 = m_ref_builder->get_widget<Gtk::Button>("input_9");
  m_button_dot = m_ref_builder->get_widget<Gtk::Button>("input_dot");

  m_button_0->signal_clicked().connect([&] { putCharToDisplay("0"); });
  m_button_1->signal_clicked().connect([&] { putCharToDisplay("1"); });
  m_button_2->signal_clicked().connect([&] { putCharToDisplay("2"); });
  m_button_3->signal_clicked().connect([&] { putCharToDisplay("3"); });
  m_button_4->signal_clicked().connect([&] { putCharToDisplay("4"); });
  m_button_5->signal_clicked().connect([&] { putCharToDisplay("5"); });
  m_button_6->signal_clicked().connect([&] { putCharToDisplay("6"); });
  m_button_7->signal_clicked().connect([&] { putCharToDisplay("7"); });
  m_button_8->signal_clicked().connect([&] { putCharToDisplay("8"); });
  m_button_9->signal_clicked().connect([&] { putCharToDisplay("9"); });
  m_button_dot->signal_clicked().connect([&] { putCharToDisplay("."); });
  m_button_plus->signal_clicked().connect([&] { putCharToDisplay("+"); });
  m_button_minus->signal_clicked().connect([&] { putCharToDisplay("-"); });
  m_button_multiply->signal_clicked().connect([&] { putCharToDisplay("*"); });
  m_button_divide->signal_clicked().connect([&] { putCharToDisplay("/"); });
  m_button_lparen->signal_clicked().connect([&] { putCharToDisplay("("); });
  m_button_rparen->signal_clicked().connect([&] { putCharToDisplay(")"); });

  m_button_equal->signal_clicked().connect([&] {
    try {
      Parser parser(m_label_display->get_label());
      ss_display.str("");
      ss_display << parser.parse();
      m_label_display->set_label(ss_display.str());
      ss_display.str("");
    } catch (std::exception &e) {
      e.what();
      m_label_display->set_label("ERROR");
    }
  });

  m_button_clear->signal_clicked().connect([&] {
    ss_display.str("");
    m_label_display->set_label("");
  });
}
