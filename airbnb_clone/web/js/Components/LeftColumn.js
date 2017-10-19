import React from 'react';
import styles from 'styles/leftColumn.css';
import States from 'js/Components/ConnectStatesSelector'

export default class LeftColumn extends React.Component {
    render () {
        return (
            <aside className={styles.leftColumn}>
                <States />
            </aside>
        );
    }
}