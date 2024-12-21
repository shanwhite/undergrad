-- DATA DUMP for database: `cs230_u230547`

-- --------------------------------------

-- create 'UserInfo' table
CREATE TABLE `cs230_u230547`.`UserInfo` (
    `UserID` INT(3) NOT NULL,
    `Title` VARCHAR(10) COLLATE utf8_unicode_ci DEFAULT NULL,
    `FirstName` VARCHAR(30) COLLATE utf8_unicode_ci NOT NULL,
    `Surname` VARCHAR(30) COLLATE utf8_unicode_ci NOT NULL,
    `Mobile` VARCHAR(10) COLLATE utf8_unicode_ci NOT NULL,
    `Email` VARCHAR(50) COLLATE utf8_unicode_ci NOT NULL
) ENGINE = InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci COMMENT='User Personal Information Table'; 

-- create 'HomeAddress' table
CREATE TABLE `cs230_u230547`.`HomeAddress` (
    `UserID` INT(3) NOT NULL,
    `AddressLine1` VARCHAR(100) COLLATE utf8_unicode_ci NOT NULL ,
    `AddressLine2` VARCHAR(100) COLLATE utf8_unicode_ci DEFAULT NULL ,
    `Town` VARCHAR(30) COLLATE utf8_unicode_ci NOT NULL ,
    `CountyCity` VARCHAR(30) COLLATE utf8_unicode_ci NOT NULL ,
    `Eircode` VARCHAR(8) COLLATE utf8_unicode_ci NOT NULL
) ENGINE = InnoDB CHARSET=utf8 COLLATE=utf8_unicode_ci COMMENT='User Home Address Table'; 

-- create 'ShippingAddress' table
CREATE TABLE `cs230_u230547`.`ShippingAddress` (
    `UserID` INT(3) NOT NULL,
    `AddressLine1` VARCHAR(100) COLLATE utf8_unicode_ci NOT NULL ,
    `AddressLine2` VARCHAR(100) COLLATE utf8_unicode_ci DEFAULT NULL ,
    `Town` VARCHAR(30) COLLATE utf8_unicode_ci NOT NULL ,
    `CountyCity` VARCHAR(30) COLLATE utf8_unicode_ci NOT NULL ,
    `Eircode` VARCHAR(8) COLLATE utf8_unicode_ci NOT NULL
) ENGINE = InnoDB CHARSET=utf8 COLLATE=utf8_unicode_ci COMMENT='User Shipping Address Table'; 

-- --------------------------------------

-- dumping data into 'UserInfo' table
-- 7 examples (already hardcoded 3 in the assignment-04.js file)
INSERT INTO `UserInfo`
(`UserID`, `Title`, `FirstName`, `Surname`, `Mobile`, `Email`) VALUES
('4', 'Mr', 'Joe', 'Bloggs', '0891237890', 'joe.bloggs@somewhere.com'),
('5', 'Mrs', 'Jane', 'Bloggs', '0894674921', 'jane.bloggs@somewhere.com'),
('6', 'Mr', 'John', 'Keating', '0871426394', 'john.keating@somewhere.com'),
('7', 'Dr', 'Julie', 'James', '0834918591', 'julie@james.com'),
('8', 'Miss', 'Jesse', 'James', '0858294718', 'jesse@james.net'),
('9', 'Ms', 'Jocelyn', 'Kim', '0851894231', 'jocelyn.kim@mu.ie'),
('10', 'Dr', 'Bob', 'Dylan', '0878298274', 'bob.dylan@mail.com');

-- dumping data into 'HomeAddress' table
INSERT INTO `HomeAddress`
(`UserID`, `AddressLine1`, `AddressLine2`, `Town`, `CountyCity`, `Eircode`) VALUES
('4', 'Number 123', 'Brickwell Lane', 'Dublin 3', 'Dublin', 'D03 W92B'),
('5', 'Number 123', 'Brickwell Lane', 'Dublin 3', 'Dublin', 'D03 W92B'),
('6', '96 Birch Road', 'Maynooth Estates', 'Maynooth', 'Kildare', 'W23 L96P'),
('7', '94 Cedar Lane', 'Maynooth Estates', 'Maynooth', 'Kildare', 'W23 L94Z'),
('8', '94 Cedar Lane', 'Maynooth Estates', 'Maynooth', 'Kildare', 'W23 L94Z'),
('9', 'Maple 3A Courtyard Apartments', 'Maynooth University', 'Maynooth', 'Kildare', 'W23 C6T0'),
('10', '789 Stonewood Alley', 'Ballymote Residences', 'Ballymote', 'Sligo', 'F56 PV38');

-- dumping data into 'ShippingAddress' table
INSERT INTO `ShippingAddress`
(`UserID`, `AddressLine1`, `AddressLine2`, `Town`, `CountyCity`, `Eircode`) VALUES
('4', 'Number 123', 'Brickwell Lane', 'Dublin 3', 'Dublin', 'D03 W92B'),
('5', 'Number 123', 'Brickwell Lane', 'Dublin 3', 'Dublin', 'D03 W92B'),
('6', '96 Birch Road', 'Maynooth Estates', 'Maynooth', 'Kildare', 'W23 L96P'),
('7', '94 Cedar Lane', 'Maynooth Estates', 'Maynooth', 'Kildare', 'W23 L94Z'),
('8', '94 Cedar Lane', 'Maynooth Estates', 'Maynooth', 'Kildare', 'W23 L94Z'),
('9', 'Maple 3A Courtyard Apartments', 'Maynooth University', 'Maynooth', 'Kildare', 'W23 C6T0'),
('10', '789 Stonewood Alley', 'Ballymote Residences', 'Ballymote', 'Sligo', 'F56 PV38');