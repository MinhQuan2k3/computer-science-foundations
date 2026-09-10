-- Create Database
IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'AnimationStudioDB')
BEGIN
    CREATE DATABASE AnimationStudioDB;
END;
GO

USE AnimationStudioDB;
GO

-- Cleanup tables
IF OBJECT_ID('Characters', 'U') IS NOT NULL DROP TABLE Characters;
IF OBJECT_ID('Movies', 'U') IS NOT NULL DROP TABLE Movies;
IF OBJECT_ID('Directors', 'U') IS NOT NULL DROP TABLE Directors;
GO

-- Table Definitions
CREATE TABLE Directors (
    DirectorID INT PRIMARY KEY IDENTITY(1,1),
    FullName NVARCHAR(100) NOT NULL,
    Country NVARCHAR(50)
);

CREATE TABLE Movies (
    MovieID INT PRIMARY KEY IDENTITY(1,1),
    Title NVARCHAR(150) NOT NULL,
    ReleaseYear INT CHECK (ReleaseYear >= 1900),
    BoxOfficeMillions DECIMAL(10,2),
    DirectorID INT NULL,
    FOREIGN KEY (DirectorID) REFERENCES Directors(DirectorID) ON DELETE SET NULL
);

CREATE TABLE Characters (
    CharacterID INT PRIMARY KEY IDENTITY(1,1),
    CharacterName NVARCHAR(100) NOT NULL,
    Role NVARCHAR(50),
    MovieID INT NULL,
    FOREIGN KEY (MovieID) REFERENCES Movies(MovieID) ON DELETE CASCADE
);
GO

-- Seed Data
INSERT INTO Directors (FullName, Country) VALUES 
(N'Hayao Miyazaki', N'Japan'),
(N'Pete Docter', N'USA'),
(N'Makoto Shinkai', N'Japan'),
(N'Unknown Director', N'Unknown');

INSERT INTO Movies (Title, ReleaseYear, BoxOfficeMillions, DirectorID) VALUES 
(N'Spirited Away', 2001, 395.8, 1),
(N'Mononoke Hime', 1997, 194.3, 1),
(N'Inside Out', 2015, 858.8, 2),
(N'Your Name', 2016, 382.2, 3),
(N'Independent Short', 2023, 0.5, NULL);

INSERT INTO Characters (CharacterName, Role, MovieID) VALUES 
(N'Chihiro Ogino', N'Protagonist', 1),
(N'Haku', N'Deuteragonist', 1),
(N'Joy', N'Protagonist', 3),
(N'Sadness', N'Deuteragonist', 3),
(N'Taki Tachibana', N'Protagonist', 4),
(N'Mitsuha Miyamizu', N'Protagonist', 4),
(N'Mascot Cat', N'Extra', NULL);
GO

-- 1. INNER JOIN: Phim và Đạo diễn tương ứng
SELECT M.Title, M.ReleaseYear, D.FullName AS Director
FROM Movies M
INNER JOIN Directors D ON M.DirectorID = D.DirectorID;

-- 2. LEFT JOIN: Tất cả các phim (kể cả phim không có Đạo diễn)
SELECT M.Title, COALESCE(D.FullName, N'No Director') AS Director
FROM Movies M
LEFT JOIN Directors D ON M.DirectorID = D.DirectorID;

-- 3. RIGHT JOIN: Tất cả đạo diễn (kể cả người chưa làm phim nào trong DB)
SELECT D.FullName AS Director, M.Title
FROM Movies M
RIGHT JOIN Directors D ON M.DirectorID = D.DirectorID;

-- 4. FULL OUTER JOIN: Liệt kê toàn bộ phim và đạo diễn dù khớp hay không
SELECT M.Title, D.FullName AS Director
FROM Movies M
FULL OUTER JOIN Directors D ON M.DirectorID = D.DirectorID;

-- 5. GROUP BY & HAVING: Tính tổng doanh thu theo quốc gia đạo diễn (> $500M)
SELECT D.Country, SUM(M.BoxOfficeMillions) AS TotalBoxOfficeMillions
FROM Movies M
JOIN Directors D ON M.DirectorID = D.DirectorID
GROUP BY D.Country
HAVING SUM(M.BoxOfficeMillions) > 500;
