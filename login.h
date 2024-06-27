#ifndef LOGIN_H
#define LOGIN_H

#include <QString>

class Login {
public:
    bool authenticate(const QString &username, const QString &password);
    bool isValidUsername(const QString &username);
    bool isValidPassword(const QString &password);
};

#endif // LOGIN_H
