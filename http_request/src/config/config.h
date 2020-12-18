//
// Created by li on 2020/12/16.
//

#ifndef HTTP_REQUEST_CONFIG_H
#define HTTP_REQUEST_CONFIG_H

namespace conf {
    class config {
    public:
        config();
        static *conf globalConfig() {
            if (config == nullptr) {

            }
        }

    };

private:
    static *config = nullptr;

}

#endif //HTTP_REQUEST_CONFIG_H
