import React from 'react';
import {render} from 'react-dom';
import app from 'styles/app.css';
import reset from 'styles/reset.css';
import App from 'js/Components/';
import StateReducer from 'js/Reducers/states';

import {
    applyMiddleware,
    combineReducers,
    createStore,
} from 'redux';

// ??? whats up with thunk and middleware ???
import thunk from 'redux-thunk';

// store is created AND reducers are combined here.
const store = createStore(
    combineReducers({ StateReducer }),
    applyMiddleware(thunk)
);

// provider imported and wrapped around app
import {
    Provider,
} from 'react-redux';

render(
    <Provider store={store}>
        <App />
    </Provider>,
    document.getElementById('content')
);