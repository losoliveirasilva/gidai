set(agenda_SRC
    Agenda.cpp
    Main.cpp
    )

add_executable(agenda ${agenda_SRC})
set_property(TARGET agenda PROPERTY CXX_STANDARD 14)
