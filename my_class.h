/**
 * @author wuxw
 * @date 10/8/23
 * @desc ...
 */
//
// Created by 朱小争 on 10/8/23.
//

#ifndef QTCXX_MY_CLASS_H
#define QTCXX_MY_CLASS_H

#include <QtCore>
#include <QObject>
#include <QCoreApplication>
#include <QMetaObject>
#include <QMetaProperty>


class MyObject : public QObject
{
Q_OBJECT
    Q_PROPERTY(int myProperty READ myProperty WRITE setMyProperty NOTIFY myPropertyChanged)
    Q_PROPERTY(QString myStringProperty READ myStringProperty WRITE setMyStringProperty NOTIFY myStringPropertyChanged)

public:
    explicit MyObject(QObject *parent = nullptr) : QObject(parent), m_myProperty(0) {}

    int myProperty() const { return m_myProperty; }
    void setMyProperty(int value) { m_myProperty = value; emit myPropertyChanged(); }

    QString myStringProperty() const { return m_myStringProperty; }
    void setMyStringProperty(const QString &value) { m_myStringProperty = value; emit myStringPropertyChanged(); }

signals:
    void myPropertyChanged();
    void myStringPropertyChanged();

private:
    int m_myProperty;
    QString m_myStringProperty;
    int myVlaue;
};

#endif  // QTCXX_MY_CLASS_H
