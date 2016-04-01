
      template<typename V1, typename V2>
      float _dist(const V1& v1, const V2& v2)
      {
	assert(v1.size() == v2.size());
	typename V1::const_iterator it1 = v1.begin(), it2 = v2.begin();
	float res = 0.0f;
	while (it1 != v1.end())
	  {
	    float v = (float)*it1 - (float)*it2;
	    res += v * v;
	    ++it1;
	    ++it2;
	  }
	return res;
      }
            
      template<typename T>
      struct _compare_dist_f
      {
	_compare_dist_f(const T& v) : _v(v) {}
	const T _v;
	bool operator()(const T& v1, const T& v2) const
	{
	  assert(v1.size() == _v.size());
	  assert(v2.size() == _v.size());
	  return _dist(v1, _v) < _dist(v2, _v);
	}
      };
#endif
