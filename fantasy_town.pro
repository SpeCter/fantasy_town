TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt
DEFINES += SFML_STATIC
LIBS += -Le:/libs/lib
INCLUDEPATH += e:/libs/include
INCLUDEPATH += e:/libs/imgui
QMAKE_CXXFLAGS_DEBUG += -g
CONFIG(release, debug|release): LIBS += -lsfml-graphics-s -lfreetype -ljpeg -lsfml-window-s -lopengl32 -lgdi32 -lsfml-system-s -lwinmm

CONFIG(debug, debug|release): LIBS += -lsfml-graphics-s-d -lfreetype -ljpeg -lsfml-window-s-d -lopengl32 -lgdi32 -lsfml-system-s-d -lwinmm

SOURCES += main.cpp \
    Type.cpp \
    World.cpp \
    ComponentManager.cpp \
    TaskManager.cpp \
    Systems/MovementSystem.cpp \
    Systems/TaskSystem.cpp \
    Tasks/GotoTask.cpp \
    Systems/RenderSystem.cpp \
    imgui-SFML.cpp \
    imgui.cpp \
    imgui_draw.cpp \
    imgui_demo.cpp \
    Components/Velocity.cpp \
    Components/Position.cpp \
    Components/Job.cpp \
    Components/Sprite.cpp \
    Components/TaskQueue.cpp

HEADERS += \
    Component.hpp \
    ComponentSystem.hpp \
    ComponentManager.hpp \
    Type.hpp \
    World.hpp \
    Entity.hpp \
    TaskManager.hpp \
    Position.hpp \
    Velocity.hpp \
    Job.hpp \
    JobSystem.hpp \
    MovementSystem.hpp \
    AutomoveSystem.hpp \
    Sprite.hpp \
    RenderSystem.hpp \
    Components.hpp \
    Systems.hpp \
    Task.hpp \
    GotoTask.hpp \
    Components/Component.hpp \
    Components/Components.hpp \
    Components/Job.hpp \
    Components/Position.hpp \
    Components/Sprite.hpp \
    Components/Velocity.hpp \
    Systems/AutomoveSystem.hpp \
    Systems/ComponentSystem.hpp \
    Systems/JobSystem.hpp \
    Systems/MovementSystem.hpp \
    Systems/RenderSystem.hpp \
    Systems/Systems.hpp \
    Components/TaskQueue.hpp \
    Systems/TaskSystem.hpp \
    Tasks/GotoTask.hpp \
    Tasks/Task.hpp \
    Tasks/TaskManager.hpp \
    Tasks/GetWood.hpp \
    Tasks/ChopWood.hpp \
    Tasks/Wait.hpp
