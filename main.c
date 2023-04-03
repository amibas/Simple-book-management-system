#include <stdio.h>
#include "Gui.h"

int main() {
    int selet = mainMenu();
    while (selet != 2) {
        selet = mainMenu();
    }
    endMenu();

    return 0;
}
