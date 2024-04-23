-- 코드를 입력하세요


SELECT CONCAT('/home/grep/src/', a.BOARD_ID,'/',a.FILE_ID, a.FILE_NAME, a.FILE_EXT) AS FILE_PATH
FROM used_goods_file AS a
JOIN used_goods_board AS b ON a.BOARD_ID = b.BOARD_ID
WHERE b.views = (    
    SELECT MAX(views)
    FROM used_goods_board
)
order by a.FILE_ID desc
