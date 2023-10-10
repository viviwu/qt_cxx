//
// Created by viviwu on 2023/10/10.
//

#ifndef QTCXX_NETWORK_INFO_H
#define QTCXX_NETWORK_INFO_H

//获取IP地址 这个方法一般是
QString getHostIpAddress();

// 获取Mac地址
QString getHostMacAddress();

//外网的获取方法，通过爬网页来获取外网IP
//公网ip
QString GetInternetIP();


#endif  // QTCXX_NETWORK_INFO_H
