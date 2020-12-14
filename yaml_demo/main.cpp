//
// Created by li on 2020/12/14.
//
#include <string>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/node/parse.h>

struct container {
    std::string name;
    int age;

//    container& operator=(const container& a)
//    {
//        name=a.name;
//        age=a.age;
//        return *this;
//    }
    // equality comparison. doesn't modify object. therefore const.
//    bool operator==(const container &a) const {
//        return (name == a.name && age == a.age);
//    }
};


namespace YAML {
    template<>
    struct convert<container> {
        static Node encode(const container &rhs) {
            Node node;
            node.push_back(rhs.name);
            node.push_back(rhs.age);
            return node;
        }

        static bool decode(const Node &node, container &rhs) {
            std::cout << node.Type() << std::endl;

            rhs.name = node["name"].as<std::string>();
            rhs.age = node["age"].as<int>();
            return true;
        }
    };
}

struct label {
    std::string app;
    std::string image;
};

namespace YAML {
    template<>
    struct convert<label> {
        static Node encode(const label &rhs) {
            Node node;
            node.push_back(rhs.app);
            node.push_back(rhs.image);
            return node;
        }

        static bool decode(const Node &node, label &rhs) {
            std::cout << node.Type() << std::endl;
            rhs.app = node["app"].as<std::string>();
            rhs.image = node["image"].as<std::string>();
            return true;
        }
    };
}

template<typename T>
struct myt;

template<>
struct myt<label> {
    static bool abc() {
        return true;
    }
};

template<>
struct myt<int> {
    static bool def() {
        return true;
    }
};
template <typename T>
struct my_as_if;

class MyNode {
public:
    template<typename T>
    T as() const {
        return my_as_if<T>(*this)();
    }
};



template <typename T>
struct my_as_if {
    explicit my_as_if(const MyNode& node_) : node(node_) {}
    const MyNode& node;

    T operator()() const {

        T t;
        if (myt<T>::abc())
            return t;
        throw "err";
    }
};
int main(int argc, char **argv) {
    //label myl;
    myt<label>::abc();
    myt<int>::def();
    MyNode mn1;
    mn1.as<label>();


    std::string config_path = "/Users/li/Developer/cplus_workspace/mycplusdemo/yaml_demo/config.yaml";
    std::cout << config_path << std::endl;
    YAML::Node config = YAML::LoadFile(config_path);

    if (config["api"]) {
        std::cout << "api: " << config["api"].as<std::string>() << std::endl;
    }
    std::cout << "api: " << config["api"].Type() << std::endl;
    std::cout << "v: " << config["v"].as<int>() << std::endl;

    if (config["label"]) {
        label l = config["label"].as<label>();
        std::cout << config["label"].Type() << " app: " << l.app << " image: " << l.image << std::endl;
    }
    if (config["containers"]) {
        YAML::Node cn = config["containers"];
        std::cout << cn << "\n" << "type: " << cn.Type() << std::endl;
        if (cn.IsSequence()) {
            std::cout << "sequence" << std::endl;
            for (auto n : cn) {
                std::cout << "v: " << n << std::endl;
                auto c = n.as<container>();
                std::cout << "container: name" << c.name << std::endl;
            }
        }
        std::cout << cn[0] << std::endl;
        std::vector<container> vi = config["containers"].as<std::vector<container>>();

        for (std::vector<container>::iterator it = vi.begin(); it != vi.end(); ++it) {
            std::cout << "vector: name: " << it->name << " age: " << it->age << std::endl;
        }
    }

    return 0;
}

