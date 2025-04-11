#ifndef API_INTERFACE_H
#define API_INTERFACE_H

#include <string>

class APIInterface {
public:
    APIInterface();
    ~APIInterface();

    // Functions to be called by each button
    void handleRedButton();
    void handleGreenButton();
    void handleBlueButton();
    void handleYellowButton();

private:
    // Private helper methods if needed
};

#endif // API_INTERFACE_H 