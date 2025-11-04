#ifndef CINEMA_MANAGEMENT_UTILIDADESCONSOLE_H
#define CINEMA_MANAGEMENT_UTILIDADESCONSOLE_H

#include <iostream>
#include <limits>

namespace UtilidadesConsole {

    inline void limparBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inline void pausar() {
        std::cout << "\nPressione ENTER para continuar...";
        std::cin.get();
    }

    inline void limparTela() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

} // namespace UtilidadesConsole

#endif // CINEMA_MANAGEMENT_UTILIDADESCONSOLE_H
