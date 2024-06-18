//
// Created by jm on 2024/6/15.
//

#ifndef GTKMM_DEMO_CALCULATOR_HPP_
#define GTKMM_DEMO_CALCULATOR_HPP_

#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/grid.h>

class CalculatorWindow : public Gtk::Window {
 public:
  CalculatorWindow(Window *window,
                   const Glib::RefPtr<Gtk::Builder> &ref_glade,
                   const Glib::RefPtr<Gtk::CssProvider> &ref_provider);

 protected:
  Glib::RefPtr<Gtk::Builder> m_ref_builder;
  Glib::RefPtr<Gtk::CssProvider> m_ref_css_provider;

 private:
  /* The Label used to display expression */
  Gtk::Label *m_label_display = nullptr;
  std::stringstream ss_display;

  /* Functional button */
  Gtk::Button *m_button_clear = nullptr;

  /* Control button */
  Gtk::Button *m_button_divide = nullptr;
  Gtk::Button *m_button_multiply = nullptr;
  Gtk::Button *m_button_minus = nullptr;
  Gtk::Button *m_button_plus = nullptr;
  Gtk::Button *m_button_equal = nullptr;

  /* Number button */
  Gtk::Button *m_button_0 = nullptr;
  Gtk::Button *m_button_dot = nullptr;
  Gtk::Button *m_button_1 = nullptr;
  Gtk::Button *m_button_2 = nullptr;
  Gtk::Button *m_button_3 = nullptr;
  Gtk::Button *m_button_4 = nullptr;
  Gtk::Button *m_button_5 = nullptr;
  Gtk::Button *m_button_6 = nullptr;
  Gtk::Button *m_button_7 = nullptr;
  Gtk::Button *m_button_8 = nullptr;
  Gtk::Button *m_button_9 = nullptr;
  Gtk::Button *m_button_lparen = nullptr;
  Gtk::Button *m_button_rparen = nullptr;

 private:
  void setupWidgets();
  void putCharToDisplay(const std::string &str);

};

#endif //GTKMM_DEMO_CALCULATOR_HPP_
