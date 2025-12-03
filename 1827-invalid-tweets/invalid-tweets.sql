-- Write your PostgreSQL query statses
select tweet_id from tweets
where length(content)>15;