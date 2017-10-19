import mysql.connector

cnx = mysql.connector.connect(user='student', password='aLQQLXGQp2rJ4Wy5',
                              host='173.246.108.142',
                              port='3306',
                              database='Project_169',
                              charset='utf8',
                              )

cursor = cnx.cursor()

query = ("SELECT name FROM TVShow GROUP BY name ASC")
cursor.execute(query)
res = cursor.fetchall()

for name in res:
    print name[0] + ":"
    season = ("SELECT Season.number, Season.id FROM Season LEFT JOIN TVShow ON Season.tvshow_id = TVShow.id WHERE TVShow.name = " + "'" + name[0] + "'")
    cursor.execute(season)
    seasons = cursor.fetchall()
    for num in seasons:
        print "\tSeason" + str(num[0]) + ":"
        episode = ("SELECT number, name FROM Episode WHERE season_id = " + str(num[1]))
        cursor.execute(episode)
        episodes = cursor.fetchall()
        for ep in episodes:
            print "\t\t" + str(ep[0]) + ": " + ep[1]
            
cnx.close()
            
