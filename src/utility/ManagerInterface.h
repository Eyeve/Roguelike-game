#ifndef ROGUELIKE_GAME_MANAGER_INTERFACE_H
#define ROGUELIKE_GAME_MANAGER_INTERFACE_H

#include <iostream>


template<typename Key, typename T>
class ManagerInterface {

public:
    virtual ~ManagerInterface() = default;

    int initialize();
    const T& get(Key key) const;

protected:
    ManagerInterface();

    virtual int init() = 0;
    virtual const T& getHandler(Key key) const = 0;

private:
    bool initialized;
};

template<typename Key, typename T>
ManagerInterface<Key, T>::ManagerInterface(): initialized(false) {

}


template<typename Key, typename T>
int ManagerInterface<Key, T>::initialize() {
    int code = init();
    initialized = !code;
    return code;
}

template<typename Key, typename T>
const T& ManagerInterface<Key, T>::get(Key key) const {
    if (!initialized)
        std::cerr << "ManagerInterface not initialized!\n";
    return getHandler(key);
}

#endif
