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

int main(int argc, char **argv) {
    std::string config_path = "/Users/li/Developer/cplus_workspace/mycplusdemo/yaml_demo/config.yaml";
    std::cout << config_path << std::endl;
    YAML::Node config = YAML::LoadFile(config_path);

    if (config["api"]) {
        std::cout << "api: " << config["api"].as<std::string>() << "\n";
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

