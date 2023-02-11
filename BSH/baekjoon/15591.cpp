#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unsigned n, q;
	unsigned pi, qi, ri;
	unsigned k, v;

	cin >> n >> q;

	vector<map<unsigned, unsigned>> edge_cost(n + 1);

	for (unsigned int i = 0; i < n - 1; i++)
	{
		cin >> pi >> qi >> ri;
		edge_cost[pi][qi] = ri;
		edge_cost[qi][pi] = ri;
	}

	vector<pair<unsigned, unsigned>> questions(q);
	for (unsigned i = 0; i < q; i++)
	{
		cin >> k >> v;
		questions[i] = make_pair(k, v);
	}

	for (const auto& i : questions)
	{
		const unsigned k_local = i.first;
		const unsigned v_local = i.second;

		unsigned answer = 0;
		queue<unsigned> my_queue;
		vector<bool> visited(n + 1, false);

		visited[v_local] = true;
		my_queue.push(v_local);

		while (!my_queue.empty())
		{
			const unsigned current = my_queue.front();
			my_queue.pop();

			for (const auto& it : edge_cost[current])
			{
				if (visited[it.first])
					continue;

				visited[it.first] = true;

				if (it.second >= k_local)
				{
					my_queue.push(it.first);
					answer += 1;
				}
			}
		}
		cout << answer << "\n";
	}
}
