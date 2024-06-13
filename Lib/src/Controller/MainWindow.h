#pragma once
#include "../../UIInterface.h"
#include <QVector>
#include <QQmlApplicationEngine>
#include <optional>
#include <QPointer>
#include <QQuickView>
class MainWindow: public CUI
{
    public:
        void init(QCoreApplication*) override;

        virtual void addResourcePath(const QString&) override;

        virtual void exec(bool usedDefaultPath=true) override;

        virtual void setWindowEntry(const QString&) override;

    private:

        QVector<QString> m_registeredPath;

        QPointer<QCoreApplication> m_applicationPointer = nullptr;

        QString m_applicationDirPath = {};

        QQuickView m_window;

        std::optional<QString> m_entryPath={};

};

// extern "C" LIBRARY_API CUI* queryInterface() {return new MainWindow;}
IMPLEMENT_PLUGIN(CUI, MainWindow);
