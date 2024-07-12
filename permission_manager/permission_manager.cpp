#include "permission_manager.h"

namespace csp {
namespace trade_client {

PermissionManager::PermissionManager() {}

void PermissionManager::setUserPermissions(const std::unordered_set<Permission> &permissions)
{
    user_permissions = permissions;
}

void PermissionManager::addUserPermission(Permission permission)
{
    user_permissions.insert(permission);
}

bool PermissionManager::hasPermission(Permission permission) const
{
    return user_permissions.count(permission) > 0;
}

} // namespace trade_client
} // namespace csp
