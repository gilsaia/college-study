CREATE TABLE Cl_United(
    Cl_United_Name CHAR(20) PRIMARY KEY,
    Cl_United_Position INT,
    Cl_United_Project_Shield INT
)
CREATE TABLE Cl_Location(
    Cl_Location_Site_Name CHAR(20) PRIMARY KEY,
    Cl_Location_Five_Element INT,
    Cl_Location_Resources INT,
    Cl_Location_Owner_United CHAR(20) REFERENCES Cl_United(Cl_United_Name)
)
CREATE TABLE Cl_Character(
    Cl_Character_ID INT PRIMARY KEY,
    Cl_Character_name VARCHAR(50),
    Cl_Character_Identity INT,
    Cl_Character_Postion INT,
    Cl_Character_Reiki REAL,
    Cl_Character_Level INT,
    Cl_Character_Location CHAR(20) REFERENCES Cl_Location(Cl_Location_Site_Name),
    Cl_Character_Belongs_to_united CHAR(20) REFERENCES Cl_United(Cl_United_Name),
)
CREATE TABLE Cl_Relationship(
    Cl_Relationship_Main_Body_ID INT PRIMARY KEY REFERENCES Cl_Character(Cl_Character_ID),
    Cl_Relationship_Object_Body_ID INT REFERENCES Cl_Character(Cl_Character_ID),
    Cl_Relationship_Relation INT
)
CREATE TABLE Cl_Condition(
    Cl_Condition_Character_ID INT PRIMARY KEY REFERENCES Cl_Character(Cl_Character_ID),
    Cl_Condition_Scourge REAL,
    Cl_Condition_Injured REAL,
    Cl_Condition_Poisoning REAL,
    Cl_Condition_Qualification INT
)
CREATE TABLE Cl_Seven_Natural_Instinct(
    Cl_Seven_Natural_Instinct_Character_ID INT PRIMARY KEY REFERENCES Cl_Condition(Cl_Condition_Character_ID),
    Cl_Seven_Natural_Instinct_Brave_and_Strong INT,
    Cl_Seven_Natural_Instinct_Perseverance INT,
    Cl_Seven_Natural_Instinct_Ability_In_Swimming INT,
    Cl_Seven_Natural_Instinct_Fate INT,
    Cl_Seven_Natural_Instinct_Calm INT,
    Cl_Seven_Natural_Instinct_Intellgent INT,
    Cl_Seven_Natural_Instinct_Exquisite INT
)
CREATE TABLE Cl_Location_Influence(
    Cl_Location_Influence_Name CHAR(20) REFERENCES Cl_Location(Cl_Location_Site_Name),
    Cl_Location_Influence_ID INT REFERENCES Cl_Condition(Cl_Condition_Character_ID),
    Cl_Location_Influence_Influences INT,
    PRIMARY KEY (Cl_Location_Influence_ID,Cl_Location_Influence_Name)
)
CREATE TABLE Cl_Items(
    Cl_Items_ID INT PRIMARY KEY,
    Cl_Items_Name VARCHAR(50),
    Cl_Items_Order INT,
    Cl_Items_Effect INT,
    Cl_Items_Owner_ID INT REFERENCES Cl_Character(Cl_Character_ID)
)
CREATE TABLE Cl_Items_Dress_Up(
    Cl_Items_Dress_Up_ID INT PRIMARY KEY REFERENCES Cl_Items(Cl_Items_ID),
    Cl_Items_Dress_Up_Defense INT,
    Cl_Items_Dress_Up_Special_Skills INT
)
CREATE TABLE Cl_Character_Equipment(
    Cl_Character_Equipment_Character_ID INT REFERENCES Cl_Character(Cl_Character_ID),
    Cl_Character_Equipment_Equipment_ID INT REFERENCES Cl_Items_Dress_Up(Cl_Items_Dress_Up_ID),
    PRIMARY KEY (Cl_Character_Equipment_Character_ID,Cl_Character_Equipment_Equipment_ID)
)
CREATE TABLE Cl_Items_Magic_Weapon(
    Cl_Items_Magic_Weapon_ID INT PRIMARY KEY REFERENCES Cl_Items(Cl_Items_ID),
    Cl_Items_Magic_Weapon_Attack INT,
    Cl_Items_Magic_Weapon_Lower_Distance INT,
    Cl_Items_Magic_Weapon_Higher_Distance INT,
    Cl_Items_Magic_Weapon_Five_Element INT
)
CREATE TABLE Cl_Character_Weapon(
    Cl_Character_Weapon_Character_ID INT REFERENCES Cl_Character(Cl_Character_ID),
    Cl_Character_Weapon_Weapon_ID INT REFERENCES Cl_Items_Magic_Weapon(Cl_Items_Magic_Weapon_ID),
    PRIMARY KEY (Cl_Character_Weapon_Character_ID,Cl_Character_Weapon_Weapon_ID)
)
CREATE TABLE Cl_Items_Books(
    Cl_Items_Books_ID INT PRIMARY KEY REFERENCES Cl_Items(Cl_Items_ID),
    Cl_Items_Books_Is_Complete INT,
    Cl_Items_Books_Skill INT
)
CREATE TABLE Cl_Items_Books_Achievement_Method(
    Cl_Items_Books_Achievement_Method_ID INT PRIMARY KEY REFERENCES Cl_Items_Books(Cl_Items_Books_ID),
    Cl_Items_Books_Achievement_Method_Is_Genuine INT,
    Cl_Items_Books_Achievement_Method_Species INT 
)
CREATE TABLE Cl_Character_Practice_Book(
    Cl_Character_Practice_Book_Character_ID INT REFERENCES Cl_Character(Cl_Character_ID),
    Cl_Character_Practice_Book_Book_ID INT REFERENCES Cl_Items_Books_Achievement_Method(Cl_Items_Books_Achievement_Method_ID),
    PRIMARY KEY (Cl_Character_Practice_Book_Book_ID,Cl_Character_Practice_Book_Character_ID)
)