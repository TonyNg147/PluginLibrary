#pragma once
#include "helpers.h"
#include <QString>
#include <QCoreApplication>

class CUI
{
    public:
        CUI() = default;

        virtual void init(QCoreApplication*) = 0;

        virtual void addResourcePath(const QString&) = 0;

        virtual void exec(bool=true) = 0;

        virtual void setWindowEntry(const QString&) = 0;
};

typedef CUI*(*UIInstance)();
