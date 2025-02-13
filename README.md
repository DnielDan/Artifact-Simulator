# Artifact-Simulator
Genshin Impact accurate artifact simulator returning number of runs and resin used to output desired artifact piece, main stat, and substats.

There are 5 different types of artifacts in the game [Flower, Feather, Sands, Circlet, Goblet] each having an equal chance of dropping after completing a domain run. A domain run costs 20 resin and you get 1 resin every 8 minutes(Offline/Online) or 180 per day (9 runs) with a capacity of 200 resin. A run has a 100% chance to drop one 5 star artifact and a 7% chance to drop two. The chances of one of the five artifacts dropping is equal. Artifacts all have one base stats and three to four substats(new). An artifact has an 18% chance to drop with four substats. 

An artifact cannot have duplicate sub-stats, and its sub-stats cannot be the same as the main stat. (E.g., an artifact with an ATK% main stat cannot gain an ATK% sub-stat, but could have a flat ATK sub-stat.) 

Flower:

![image](https://github.com/user-attachments/assets/dea2da5a-441f-4ddf-b0a4-a7a0ba33865f)

- One main stat: HP
- Up to 9 different substats: HP%, ATK, ATK%, DEF, DEF%, Elemental Mastery, Energy Recharge%, Crit Rate%, Crit DMG%

Feather: 

 ![image](https://github.com/user-attachments/assets/2147b886-668b-4448-aa0f-b764f214def5)

 - One main stat: ATK
 - Up to 9 different substats: ATK%, DEF, DEF%, HP, HP%, Elemental Mastery, Energy Recharge%, Crit Rate%, Crit DMG%

Sands:

![image](https://github.com/user-attachments/assets/65d0a70d-5bd2-4554-a818-0016e08220d6)

- Can be 1 of 5 main stats: HP%, ATK%, DEF%, Elemental Mastery, Energy Recharge%
- Up to 9 different substats: ATK%, DEF, DEF%, HP, HP%, Elemental Mastery, Energy Recharge%, Crit Rate%, Crit DMG%

Circlet:

![image](https://github.com/user-attachments/assets/a6768b29-e729-4b59-b396-5527fc8f0b62)

- Can be 1 of 7 main stats: HP%, ATK%, DEF%, Elemental Mastery, Crit Rate%, Crit DMG%, Healing Bonus%
- Up to 9 different substats: ATK%, DEF, DEF%, HP, HP%, Elemental Mastery, Energy Recharge%, Crit Rate%, Crit DMG%

Goblet:

![image](https://github.com/user-attachments/assets/49a07f34-79ee-448f-95c4-c4219a804884)

- Can be 1 of 12 main stats: HP%, ATK%, DEF%, Elemental Mastery, Physical DMG Bonus%, Pyro DMG Bonus%, Electro DMG Bonus%, Dendro DMG Bonus%, Cryo DMG Bonus%, Hydro DMG Bonus%, Anemo DMG Bonus%, Geo DMG Bonus%,
- Up to 9 different substats: ATK%, DEF, DEF%, HP, HP%, Elemental Mastery, Energy Recharge%, Crit Rate%, Crit DMG%

Looking at the chances, the hardest specific piece to get by far is the goblet. I have my program to stop when a domain run generates a pyro DMG Bonus% Goblet which has Crit DMG and Crit Rate as its 2 out of the 3-4 substats to see how long it takes to get the piece.

More info here: https://genshin-impact.fandom.com/wiki/Artifact/Stats 
