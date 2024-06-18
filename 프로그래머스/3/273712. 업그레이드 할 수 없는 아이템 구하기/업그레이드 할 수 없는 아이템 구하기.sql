select b.item_id,b.item_name,b.rarity from item_tree a
join item_info b on a.item_id = b.item_id
where not exists
(
    select 1 from item_tree it where it.parent_item_id = b.item_id
)
order by b.item_id desc