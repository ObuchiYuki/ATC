//
//  measure.hpp
//  ATC
//
//  Created by yuki on 2022/06/01.
//

#ifndef measure_h
#define measure_h

using namespace chrono;

template<class T, class U>
void desc(duration<T, U> v) {
    cout << duration_cast<milliseconds>(v).count() << " ms" << endl;
}

#define measure(block) {auto __b = steady_clock::now();block;print(steady_clock::now() - __b);}


#endif /* measure_h */
