import React from 'react';

import {
    STATES_FETCH_ERROR,
    STATES_FETCH_INITIATED,
    STATES_FETCH_COMPLETED    
} from 'js/Constants/StateConstants';

// LEARN MORE ABOUT SUPERAGENT
import request from 'superagent';

// LEARN MORE ABOUT NORMALIZR
// import {
//   arrayOf,
//   normalize,
//   Schema,
// } from 'normalizr';

// is the first argument of Schema the key of json or a name for the new key?
// const states = new Schema('states', {
//   idAttribute: 'id',
// });

export function stateFetchInitiated() {
    console.log('Starting request...');
    return {
        type: STATES_FETCH_INITIATED,
    };
}

export function stateFetchError(error) {
    console.log('error: ', error);
    return {
        type: STATES_FETCH_ERROR,
        error
    };
}

export function stateFetchCompleted(response) {
    // What is object.assign? normalizr stuff??
    return {
        type: STATES_FETCH_COMPLETED,
        payload: response.data 
    };
}

export function fetchStates() {
    return dispatch => {
        dispatch(stateFetchInitiated());

        //request.get("http://api.impossibleoctopusfitness.tech/states/")
        request.get("http://localhost:3333/states/").then((data) => {
                dispatch(stateFetchCompleted(data.body));
            }).catch((error) => {
                dispatch(stateFetchError(error));
            });
    };
}
