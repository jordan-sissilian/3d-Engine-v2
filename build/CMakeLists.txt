cmake_minimum_required(VERSION 3.10)
project(3DEngine)

# Spécifiez la version du langage C++
set(CMAKE_CXX_STANDARD 20)

# Inclure Qt et ses modules
find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL REQUIRED)

# Recherche de la bibliothèque OpenGL
find_package(OpenGL REQUIRED)

# Liste des fichiers source de votre projet
file(GLOB SOURCES
    "../3D_Engine/main.cpp"
    "../3D_Engine/source/*.cpp"
    "../3D_Engine/source/OpenGL/*.cpp"
)

# Spécifiez le répertoire de sortie pour les exécutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/3DEngine)

# Créez l'exécutable de votre projet
add_executable(3DEngine ${SOURCES})

# Ajoutez les bibliothèques Qt requises à votre exécutable
target_link_libraries(3DEngine PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL)

# Ajoutez la bibliothèque OpenGL
target_link_libraries(3DEngine PRIVATE OpenGL::GL)

# Définissez les options de compilation spécifiques
target_compile_options(3DEngine PRIVATE -std=c++20)
