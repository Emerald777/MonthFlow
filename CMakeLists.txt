cmake_minimum_required(VERSION 3.16)
project(MonthFlow)

# Настройки C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)      # Для Qt мета-объектов (сигналы/слоты)
set(CMAKE_AUTORCC ON)      # Для Qt ресурсов (.qrc)
set(CMAKE_AUTOUIC ON)      # Для Qt UI файлов (.ui)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# Находим Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    src/main.cpp
)

set(HEADERS
    src/Styles.h
    src/StackedPages.h
    src/DeadlineStatus.h
)

set(SOURCES_UI
    src/MainWindow.cpp
    src/ControlWidget.cpp
    src/ExpanderWidget.cpp
    src/TaskWidget.cpp
    src/NewTaskDialog.cpp
)

set(HEADERS_UI
    src/MainWindow.h
    src/ControlWidget.h
    src/ExpanderWidget.h
    src/TaskWidget.h
    src/NewTaskDialog.h
)

set(FORMS
    ui/ControlWidget.ui
    ui/NewTaskDialog.ui
)

set(RESOURCES
    res.qrc
)

source_group("Headers" FILES ${HEADERS})
source_group("Sources" FILES ${SOURCES})
source_group("Headers/Ui" FILES ${HEADERS_UI})
source_group("Sources/Ui" FILES ${SOURCES_UI})

# Создаём исполняемый файл
add_executable(${PROJECT_NAME} WIN32
    ${SOURCES} ${HEADERS}
    ${SOURCES_UI} ${HEADERS_UI}
    ${FORMS}
    ${RESOURCES}
)

# Линкуем Qt библиотеки
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Widgets
)

# Windows специфичные настройки
if(WIN32)
    # Устанавливаем иконку для .exe (если есть)
    # set(APP_ICON resources/app.ico)
    # set(CMAKE_RC_COMPILER_INIT windres)
    # add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND windres -i ${APP_ICON} -o ${CMAKE_CURRENT_BINARY_DIR}/resource.res)
    # target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/resource.res)

    # Копируем Qt DLL при сборке (для запуска без установленного Qt)
    # add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    #     COMMAND ${CMAKE_COMMAND} -E echo "Copying Qt DLLs..."
    #     COMMAND windeployqt --release --compiler-runtime ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.exe
    #     COMMENT "Deploying Qt libraries"
    # )
endif()

# Настройки компилятора
if(MSVC)
    # Включаем консоль для отладки (убери WIN32 в add_executable если нужна консоль)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /utf-8)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()

# Пути для инклудов (если есть кастомные папки)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
