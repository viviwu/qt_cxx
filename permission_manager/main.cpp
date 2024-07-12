#include <QCoreApplication>
#include "permission_manager.h"
#include <iostream>
#include <unordered_set>

// 示例用法
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建权限管理类
    PermissionManager permissionManager;

    // 模拟从服务端接收到的权限ID列表
    std::unordered_set<Permission> userPermissions = {Permission::READ};

    // 设置用户权限
    permissionManager.setUserPermissions(userPermissions);

    permissionManager.addUserPermission(Permission::WRITE);

    // 检查具体功能的可用性
    if (permissionManager.hasPermission(Permission::READ)) {
        std::cout << "Read functionality is available.\n";
    } else {
        std::cout << "Read functionality is not available.\n";
    }

    if (permissionManager.hasPermission(Permission::WRITE)) {
        std::cout << "Write functionality is available.\n";
    } else {
        std::cout << "Write functionality is not available.\n";
    }

    if (permissionManager.hasPermission(Permission::DELETE)) {
        std::cout << "Delete functionality is available.\n";
    } else {
        std::cout << "Delete functionality is not available.\n";
    }

    // return 0;
    return a.exec();
}
