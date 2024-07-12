/**
 * 权限管理类:
 * 为客户端实现一个功能“权限管理类”，预先将客户端所有可用功能定义成权限枚举项。
 * 用户登录后，根据从服务端收到的权限ID列表，决定该用户哪些客户端功能可用(有权限)。
 * 用户进入到客户端各页面时，通过查询“权限管理类”里是用户否有该功能权限，决定哪些功能是可用的。
 */

#ifndef PERMISSION_MANAGER_H
#define PERMISSION_MANAGER_H

#include <unordered_set>

namespace csp {
namespace trade_client {

// <!-- 定义权限枚举项  -->
enum class Permission { READ, WRITE, DELETE };

// <!-- 权限管理类  -->
class PermissionManager
{
public:
    PermissionManager();

    // <!-- 设置用户权限  -->
    void setUserPermissions(const std::unordered_set<Permission> &permissions);

    // <!-- 添加用户权限  -->
    void addUserPermission(Permission permission);

    // <!-- 检查用户是否具有指定权限  -->
    bool hasPermission(Permission permission) const;

private:
    std::unordered_set<Permission> user_permissions;
};

} // namespace trade_client
} // namespace csp

#endif // PERMISSION_MANAGER_H
