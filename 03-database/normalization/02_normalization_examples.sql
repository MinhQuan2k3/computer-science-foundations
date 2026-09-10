USE AnimationStudioDB;
GO

/*
  ======================================================
  UNNORMALIZED FORM (UNF)
  Bảng vi phạm 1NF: Cột Characters chứa nhiều giá trị phân tách bằng dấu phẩy.
  ------------------------------------------------------
  StudioID | StudioName | MovieTitle   | Characters
  1        | Ghibli     | Totoro       | Satsuki, Mei, Totoro
  ======================================================
*/

-- 1NF (First Normal Form): Mỗi ô chứa một giá trị nguyên tố (Atomic), có Primary Key
CREATE TABLE Animation_1NF (
    StudioID INT,
    StudioName NVARCHAR(100),
    MovieTitle NVARCHAR(100),
    CharacterName NVARCHAR(100),
    PRIMARY KEY (StudioID, MovieTitle, CharacterName)
);

/*
  VI PHẠM 2NF trong bảng 1NF:
  Primary Key là (StudioID, MovieTitle, CharacterName).
  Tuy nhiên, StudioName chỉ phụ thuộc vào một phần khóa chính là StudioID (Partial Dependency).
*/

-- 2NF (Second Normal Form): Loại bỏ Partial Dependency bằng cách tách bảng Studio
CREATE TABLE Studios_2NF (
    StudioID INT PRIMARY KEY,
    StudioName NVARCHAR(100)
);

CREATE TABLE MovieCharacters_2NF (
    StudioID INT,
    MovieTitle NVARCHAR(100),
    CharacterName NVARCHAR(100),
    PRIMARY KEY (StudioID, MovieTitle, CharacterName),
    FOREIGN KEY (StudioID) REFERENCES Studios_2NF(StudioID)
);

/*
  VI PHẠM 3NF:
  Nếu có bảng MovieDetails(MovieID, Title, StudioID, StudioHeadquarters),
  StudioHeadquarters phụ thuộc vào StudioID, mà StudioID lại phụ thuộc vào MovieID (Transitive Dependency).
*/

-- 3NF (Third Normal Form): Loại bỏ Transitive Dependency
CREATE TABLE Studios_3NF (
    StudioID INT PRIMARY KEY,
    StudioName NVARCHAR(100),
    Headquarters NVARCHAR(100)
);

CREATE TABLE Movies_3NF (
    MovieID INT PRIMARY KEY IDENTITY(1,1),
    Title NVARCHAR(150),
    StudioID INT,
    FOREIGN KEY (StudioID) REFERENCES Studios_3NF(StudioID)
);
