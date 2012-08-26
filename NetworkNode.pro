#-------------------------------------------------
#
# Project created by QtCreator 2012-08-19T15:17:41
#
#-------------------------------------------------

QT       += core gui network

TARGET = NetworkNode
TEMPLATE = app


SOURCES += main.cpp\
		networknodeapp.cpp \
	nodefinder.cpp \
    remotenode.cpp

HEADERS  += networknodeapp.hpp \
	nodefinder.hpp \
    remotenode.hpp

FORMS    += networknodeapp.ui
