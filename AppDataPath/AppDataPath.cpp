/**
 ******************************************************************************
 * @file           : AppDataPath.cpp
 * @author         : viviwu
 * @brief          : None
 * @attention      : None
 * @date           : 3/20/24
 ******************************************************************************
 */
// Created by viviwu on 3/20/24.
#include <QCoreApplication>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 获取应用程序配置目录
    QString configDir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    qDebug() << "Config Directory: " << configDir;

    // 获取应用程序数据目录
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug() << "Data Directory: " << dataDir;

    // 获取用户文档目录
    QString documentsDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    qDebug() << "Documents Directory: " << documentsDir;

    // 获取用户主目录
    QString homeDir = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << "Home Directory: " << homeDir;

    return a.exec();
}
