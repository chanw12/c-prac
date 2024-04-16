-- 코드를 입력하세요
SELECT b.user_id as USER_ID,b.nickname as NICKNAME ,concat(b.city,' ',b.street_address1,' ',b.street_address2) as 전체주소,
concat(substr(b.tlno,1,3),'-',substr(b.tlno,4,4),'-',substr(b.tlno,8,4)) as 전화번호
from used_goods_board as a
join used_goods_user as b on a.writer_id = b.user_id
where b.user_id in (select writer_id from used_goods_board
                   group by writer_id
                   having count(*) >= 3
                   )
group by USER_ID
order by USER_ID desc