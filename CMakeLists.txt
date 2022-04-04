cmake_minimum_required(VERSION 3.20)
project(LasosProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(LasosProject main.cpp internal/lasos/lang/LasosLang.cpp internal/lasos/lang/LasosLang.h internal/lasos/token/LasosToken.cpp internal/lasos/token/LasosToken.h internal/lasos/lexer/LasosLexer.cpp internal/lasos/lexer/LasosLexer.h pkg/utils/Utils.cpp pkg/utils/Utils.h)
