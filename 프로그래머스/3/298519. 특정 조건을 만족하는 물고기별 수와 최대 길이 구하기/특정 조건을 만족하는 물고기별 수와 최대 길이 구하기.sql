-- 코드를 작성해주세요
select count(*) FISH_COUNT,max(LENGTH) MAX_LENGTH,FISH_TYPE from FISH_INFO
group by FISH_TYPE
having avg(COALESCE(LENGTH,10)) >= 33
order by FISH_TYPE asc

