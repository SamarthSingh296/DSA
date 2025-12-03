-- Write your PostgreSQL query statses
select tweet_id from tweets
where char_length(content)>15;