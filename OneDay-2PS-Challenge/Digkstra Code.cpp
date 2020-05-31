struct cmp{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) a.second > b.second;
		else a.first > b.first;
	}
};
void dijkstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> q;
	fill(dist, dist + 501,1e9);
	q.push({ start,0 });
	dist[start] = 0;
	while (!q.empty()) {
		int cost = q.top().first;
		int here = q.top().second;
		q.pop();
		for (int i = 0; i < road[here].size(); i++) {
			int next = road[here][i].first;
			int next_cost = road[here][i].second;
			if (dist[next] > dist[here] + next_cost) {//작아지는 경우 갱신을 해줘야함
				dist[next] = dist[here] + next_cost;
				q.push({ dist[next],next });
			}
		}
	}
}