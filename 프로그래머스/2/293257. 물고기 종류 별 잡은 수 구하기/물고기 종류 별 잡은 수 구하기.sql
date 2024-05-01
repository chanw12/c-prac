-- 코드를 작성해주세요
select count(*) as FISH_COUNT,b.FISH_NAME from fish_info as a
join fish_name_info as b on a.FISH_TYPE = b.FISH_TYPE
group by b.FISH_NAME
order by FISH_COUNT desc

