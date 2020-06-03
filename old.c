#include <gtk/gtk.h>
#include <stdio.h>
#include< stdlib.h>
#include <string.h>

void button_clicked(GtkWidget *widget, gpointer data) {
    
  g_print("clicked\n");
}


int main(int argc, char *argv[])
{
    GtkBuilder *gtkBuilder;
    GtkWidget *window;
    GtkWidget *shut;
    gtk_init(&argc, &argv);
    
    gtkBuilder = gtk_builder_new();
    gtk_builder_add_from_file(gtkBuilder, "dahlia-layout.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "window1"));
    gtk_window_set_title(GTK_WINDOW(window), "GtkButton");
    gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
    
    g_object_unref(G_OBJECT(gtkBuilder));
    gtk_widget_show(window);
    gtk_main();

shut = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "shutBT"));

g_signal_connect(G_OBJECT(shut), "clicked", 
      G_CALLBACK(button_clicked), NULL);
    return 0;




}