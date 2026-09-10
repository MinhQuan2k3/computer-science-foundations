USE AnimationStudioDB;
GO

IF OBJECT_ID('MovieLogs', 'U') IS NOT NULL DROP TABLE MovieLogs;

CREATE TABLE MovieLogs (
    LogID INT IDENTITY(1,1), -- Sẽ tạo Clustered Index tự động nếu chọn PRIMARY KEY
    MovieCode VARCHAR(50),
    ViewCount INT,
    LogDate DATETIME
);

-- Thêm Primary Key -> Tự động tạo Clustered Index trên LogID
ALTER TABLE MovieLogs ADD CONSTRAINT PK_MovieLogs PRIMARY KEY CLUSTERED (LogID);

-- Tạo Non-Clustered Index trên MovieCode để tăng tốc truy vấn lọc theo mã phim
CREATE NONCLUSTERED INDEX IX_MovieLogs_MovieCode 
ON MovieLogs (MovieCode)
INCLUDE (ViewCount); -- Covering Index để tránh Key Lookup
GO

-- Chèn dữ liệu thử nghiệm
INSERT INTO MovieLogs (MovieCode, ViewCount, LogDate) VALUES
('MOV-GHIBLI-01', 1200, GETDATE()),
('MOV-PIXAR-01', 5000, GETDATE()),
('MOV-GHIBLI-01', 3400, DATEADD(day, -1, GETDATE()));

-- Kiểm tra Index được sử dụng (Bật 'Include Actual Execution Plan' trong SSMS)
SELECT MovieCode, ViewCount 
FROM MovieLogs 
WHERE MovieCode = 'MOV-GHIBLI-01';
