#include <gtkmm/window.h>
#include <gtkmm/application.h>

#include "src/calculator/calculator_window.hpp"

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("jm.gtkmm.calculator");

  Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("calculator.glade");
  Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();

  auto *glade_window = builder->get_widget<Gtk::Window>("window");
  auto calc_window = CalculatorWindow(glade_window, builder, css_provider);
  auto window_display = calc_window.get_display();

  css_provider->load_from_path("calculator.css");
  Gtk::CssProvider::add_provider_for_display(window_display, css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

  app->signal_activate().connect([&] {
    app->add_window(calc_window);
    calc_window.show();
  });

  return app->run(argc, argv);
}
