#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_set>

using namespace std;

enum ArtifactType {
    FLOWER,
    FEATHER,
    SANDS,
    CIRCLET,
    GOBLET
};

struct Artifact {
    ArtifactType type;
    string baseStat;
    vector<string> subStats;
};

string getBaseStat(ArtifactType type) {
    switch (type) {
        case FLOWER: return "HP+717";
        case FEATHER: return "ATK+47";
        case SANDS: {
            vector<string> sandsStats = {"HP+7.0%", "ATK+7.0%", "DEF+8.7%", "Elemental Mastery+28", "Energy Recharge+7.8%"};
            return sandsStats[rand() % sandsStats.size()];
        }
        case CIRCLET: {
            vector<string> circletStats = {"HP+7.0%", "ATK+7.0%", "DEF+8.7%", "Elemental Mastery+28", "Crit Rate+4.7%", "Crit DMG+9.3%", "Healing Bonus+5.4%"};
            return circletStats[rand() % circletStats.size()];
        }
        case GOBLET: {
            vector<string> gobletStats = {"HP+7.0%", "ATK+7.0%", "DEF+8.7%", "Elemental Mastery+28", "Physical DMG Bonus+8.7%", "Pyro DMG Bonus+7.0%", "Electro DMG Bonus+7.0%", "Cryo DMG Bonus+7.0%", "Hydro DMG Bonus+7.0%", "Dendro DMG Bonus+7.0%", "Anemo DMG Bonus+7.0%", "Geo DMG Bonus+7.0%"};
            return gobletStats[rand() % gobletStats.size()];
        }
        default: return "";
    }
}

vector<string> getSubStats() {
    vector<string> possibleSubStats = {
        "HP+209.13", "HP+239.00", "HP+268.88", "HP+298.75",
        "ATK+13.62", "ATK+15.56", "ATK+17.51", "ATK+19.45",
        "DEF+16.20", "DEF+18.52", "DEF+20.83", "DEF+23.15",
        "HP+4.08%", "HP+4.66%", "HP+5.25%", "HP+5.83%",
        "ATK+4.08%", "ATK+4.66%", "ATK+5.25%", "ATK+5.83%",
        "DEF+5.10%", "DEF+5.83%", "DEF+6.56%", "DEF+7.29%",
        "Elemental Mastery+16.32", "Elemental Mastery+18.65", "Elemental Mastery+20.98", "Elemental Mastery+23.31",
        "Energy Recharge+4.53%", "Energy Recharge+5.18%", "Energy Recharge+5.83%", "Energy Recharge+6.48%",
        "Crit Rate+2.72%", "Crit Rate+3.11%", "Crit Rate+3.50%", "Crit Rate+3.89%",
        "Crit DMG+5.44%", "Crit DMG+6.22%", "Crit DMG+6.99%", "Crit DMG+7.77%"
    };
    vector<string> subStats;
    unordered_set<string> chosenTypes;
    int numSubStats = 3 + rand() % 2; 

    while (subStats.size() < numSubStats) {
        random_shuffle(possibleSubStats.begin(), possibleSubStats.end());
        for (const auto& subStat : possibleSubStats) {
            string type = subStat.substr(0, subStat.find('+'));
            if (chosenTypes.find(type) == chosenTypes.end()) {
                subStats.push_back(subStat);
                chosenTypes.insert(type);
                if (subStats.size() == numSubStats) break;
            }
        }
    }
    return subStats;
}

Artifact generateArtifact() {
    ArtifactType type = static_cast<ArtifactType>(rand() % 5);
    Artifact artifact = {type, getBaseStat(type), getSubStats()};
    return artifact;
}

bool isDesiredArtifact(const Artifact& artifact) {
    // Change artifact type here and base stats
    if (artifact.type == GOBLET && artifact.baseStat == "Pyro DMG Bonus+7.0%") {
    // Change artifact type here and base stats

        // Change bool names here if looking for different substats 
        bool hasCritRate = false;
        bool hasCritDMG = false;
        // Change bool names here if looking for different substats 
        
        for (const auto& subStat : artifact.subStats) {
                              //Change
            if (subStat.find("Crit Rate") != string::npos) {
                hasCritRate = true;
            }
                              //Change
            if (subStat.find("Crit DMG") != string::npos) {
                hasCritDMG = true;
            }
        }       //Change      //Change
        return hasCritRate && hasCritDMG;
    }
    return false;
}

void runDomain(int& resin, int& runs, bool& found) {
    int numArtifacts = (rand() % 100 < 7) ? 2 : 1; 
    vector<Artifact> artifacts;
    for (int i = 0; i < numArtifacts; ++i) {
        artifacts.push_back(generateArtifact());
    }
    resin += 20;
    runs++;

    cout << "Run completed! You received " << numArtifacts << " artifact(s):\n";
    for (const auto& artifact : artifacts) {
        string typeName;
        switch (artifact.type) {
            case FLOWER: typeName = "Flower"; break;
            case FEATHER: typeName = "Feather"; break;
            case SANDS: typeName = "Sands"; break;
            case CIRCLET: typeName = "Circlet"; break;
            case GOBLET: typeName = "Goblet"; break;
        }
        cout << "- " << typeName << ": " << artifact.baseStat << "\n";
        for (const auto& subStat : artifact.subStats) {
            cout << "    - " << subStat << "\n";
        }
        if (isDesiredArtifact(artifact)) {
            found = true;
        }
    }
    cout << "Current resin: " << resin << "\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int resin = 0;
    int runs = 0;
    bool found = false;

    while (!found) {
        runDomain(resin, runs, found);
    }

    cout << "Desired artifact found after " << runs << " runs and " << resin << " resin.\n";
    return 0;
}